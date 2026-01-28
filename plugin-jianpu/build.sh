set -e
set -u

get_exe_or_none(){
  which "$1" 2>/dev/null || echo 'none'
}

wasm_opt="$(get_exe_or_none wasm-opt)"
if [ -e "$wasm_opt" ]; then
    : discard
else
    if [ ! -d "binaryen-version_122" ]; then
        curl -L https://github.com/WebAssembly/binaryen/releases/download/version_122/binaryen-version_122-x86_64-linux.tar.gz | tar zx
    fi
    wasm_opt=./binaryen-version_122/bin/wasm-opt
fi

if [ ! -d "wasm-minimal-protocol" ]; then
    # We clone anyway as ./Cargo.toml requires path="./wasm-minimal-protocol"
    git clone https://github.com/astrale-sharp/wasm-minimal-protocol --depth=1
fi
wasi_stub="$(get_exe_or_none wasi-stub)"
# If found, assuming having been installed
if [ ! -e "$wasi_stub" ]; then
    cd wasm-minimal-protocol/crates/wasi-stub
    cargo install --path .
    cd ../../..
    wasi_stub=wasi-stub
fi

# XXX: donno why only wasm32-wasip1 works
WASM_TARGET="${WASM_TARGET:-wasm32-wasip1}"

rustup target add $WASM_TARGET

WASI_SDK_PATH="${WASI_SDK_PATH:-/opt/wasi-sdk}"
# xxx/wasi-sdk-${WASI_VERSION_FULL}-${WASI_ARCH}-${WASI_OS}
SYSROOT=" --sysroot=${WASI_SDK_PATH}/share/wasi-sysroot"
RUSTFLAGS="-L ${WASI_SDK_PATH}/share/wasi-sysroot/lib/${WASM_TARGET} -lstatic=c++ -lstatic=c++abi" CXXSTDLIB=c++ CC="${WASI_SDK_PATH}/bin/clang" CXX="${WASI_SDK_PATH}/bin/clang++" CXXFLAGS="-fno-exceptions" cargo build --release --target $WASM_TARGET
"$wasi_stub" -r 0 "./target/${WASM_TARGET}/release/typst_jianpu.wasm" -o ../package/dist/jianpu.wasm
"$wasm_opt" ../package/dist/jianpu.wasm --all-features -O3 --enable-bulk-memory -o ../package/dist/jianpu.wasm


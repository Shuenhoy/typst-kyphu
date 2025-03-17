if [ ! -d "binaryen-version_122" ]; then
    curl -L https://github.com/WebAssembly/binaryen/releases/download/version_122/binaryen-version_122-x86_64-linux.tar.gz | tar zx
fi
if [ ! -d "wasm-minimal-protocol" ]; then
    git clone https://github.com/astrale-sharp/wasm-minimal-protocol --depth=1
fi
cd wasm-minimal-protocol/crates/wasi-stub
cargo install --path .
cd ../../..
rustup target add wasm32-wasip1
RUSTFLAGS='-L /opt/wasi-sdk/share/wasi-sysroot/lib/wasm32-wasip1 -lstatic=c++ -lstatic=c++abi' CXXSTDLIB=c++ CC=/opt/wasi-sdk/bin/clang CXX=/opt/wasi-sdk/bin/clang++ CXXFLAGS="-fno-exceptions" cargo build --release --target wasm32-wasip1
./wasm-minimal-protocol/target/release/wasi-stub -r 0 ./target/wasm32-wasip1/release/typst_jianpu.wasm -o ../package/dist/jianpu.wasm
./binaryen-version_122/bin/wasm-opt ../package/dist/jianpu.wasm -O3 --enable-bulk-memory -o ../package/dist/jianpu.wasm


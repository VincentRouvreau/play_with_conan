# Consuming packages with conan

(inspired from https://github.com/conan-io/examples2/blob/main/tutorial/consuming_packages/different_configurations )
```bash
rm -rf build

conan install . --output-folder=build --build=missing
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=./build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
```

Here, I don't know why `conan_toolchain.cmake` is not directly in build directory, and I don't know how to change it.

```txt
-- Using Conan toolchain: /home/gailuron/workspace/gudhi/play_with_conan/build/build/Release/generators/conan_toolchain.cmake
-- Conan toolchain: C++ Standard 17 with extensions ON
-- The CXX compiler identification is GNU 11.4.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Conan: Component target declared 'Eigen3::Eigen'
Eigen3 is found
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /home/gailuron/workspace/gudhi/play_with_conan/build
```
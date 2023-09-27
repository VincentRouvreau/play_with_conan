# Consuming packages with conan

(inspired from https://github.com/conan-io/examples2/blob/main/tutorial/consuming_packages/different_configurations )
```bash
rm -rf build

conan install . --output-folder=build --build=missing --options=boost/1.82.0:shared=True
# This command builds boost*.dll in C:\Users\User\.conan2\p\cmake1927748c2604b\p\bin
# This requires to append PATH environment variable with C:\Users\User\.conan2\p\cmake1927748c2604b\p\bin
# Not set by conanbuild.bat
# Nor in conan_toolchain
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=./build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
make
ctest
```

# Issue

On Windows, Boost unit_test_framework shared library path (dll) is not added to the PATH.
`ctest` fails.

## Some comments

Here, I don't know why `conan_toolchain.cmake` is not directly in build directory, and I don't know how to change it.

```txt
-- Using Conan toolchain: /home/play_with_conan/build/build/Release/generators/conan_toolchain.cmake
-- Conan toolchain: C++ Standard 17 with extensions ON
-- The CXX compiler identification is GNU 11.4.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Conan: Component target declared 'Boost::diagnostic_definitions'
-- Conan: Component target declared 'Boost::disable_autolinking'
-- Conan: Component target declared 'Boost::dynamic_linking'
-- Conan: Component target declared 'Boost::headers'
-- Conan: Component target declared 'Boost::boost'
-- Conan: Component target declared 'boost::_libboost'
-- Conan: Component target declared 'Boost::atomic'
-- Conan: Component target declared 'Boost::container'
-- Conan: Component target declared 'Boost::context'
-- Conan: Component target declared 'Boost::date_time'
-- Conan: Component target declared 'Boost::exception'
-- Conan: Component target declared 'Boost::math'
-- Conan: Component target declared 'Boost::math_c99'
-- Conan: Component target declared 'Boost::math_c99f'
-- Conan: Component target declared 'Boost::math_c99l'
-- Conan: Component target declared 'Boost::math_tr1'
-- Conan: Component target declared 'Boost::math_tr1f'
-- Conan: Component target declared 'Boost::math_tr1l'
-- Conan: Component target declared 'Boost::program_options'
-- Conan: Component target declared 'Boost::regex'
-- Conan: Component target declared 'Boost::serialization'
-- Conan: Component target declared 'Boost::stacktrace'
-- Conan: Component target declared 'Boost::stacktrace_addr2line'
-- Conan: Component target declared 'Boost::stacktrace_backtrace'
-- Conan: Component target declared 'Boost::stacktrace_basic'
-- Conan: Component target declared 'Boost::stacktrace_noop'
-- Conan: Component target declared 'Boost::system'
-- Conan: Component target declared 'Boost::test'
-- Conan: Component target declared 'Boost::test_exec_monitor'
-- Conan: Component target declared 'Boost::url'
-- Conan: Component target declared 'Boost::wserialization'
-- Conan: Component target declared 'Boost::chrono'
-- Conan: Component target declared 'Boost::coroutine'
-- Conan: Component target declared 'Boost::filesystem'
-- Conan: Component target declared 'Boost::json'
-- Conan: Component target declared 'Boost::nowide'
-- Conan: Component target declared 'Boost::prg_exec_monitor'
-- Conan: Component target declared 'Boost::random'
-- Conan: Component target declared 'Boost::thread'
-- Conan: Component target declared 'Boost::timer'
-- Conan: Component target declared 'Boost::type_erasure'
-- Conan: Component target declared 'Boost::unit_test_framework'
-- Conan: Component target declared 'Boost::wave'
-- Conan: Component target declared 'Boost::contract'
-- Conan: Component target declared 'Boost::fiber'
-- Conan: Component target declared 'Boost::fiber_numa'
-- Conan: Component target declared 'Boost::graph'
-- Conan: Component target declared 'Boost::iostreams'
-- Conan: Component target declared 'Boost::locale'
-- Conan: Component target declared 'Boost::log'
-- Conan: Component target declared 'Boost::log_setup'
-- Conan: Target declared 'boost::boost'
-- Conan: Target declared 'libbacktrace::libbacktrace'
Boost::filesystem is found
Boost::unit_test_framework is found
Boost::program_options is found
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /home/play_with_conan/build
```


## Some Tricks

### Dependencies

conan graph info -f html . > info.html
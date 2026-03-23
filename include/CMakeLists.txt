
target_sources(foo.bar PUBLIC FILE_SET HEADERS FILES
        example.hpp
        platform/linux.hpp
        platform/windows.hpp
)

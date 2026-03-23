
set(ALL_EXAMPLES
        overload01
        overload02
        overload03
        overload04
        overload05
        overload06
        overload07
        overload08
)

foreach (example ${ALL_EXAMPLES})
    add_executable(foo.bar.examples.${example})
    target_compile_definitions(foo.bar.examples.${example} PRIVATE
            WINVER=0x0A00
            _WIN32_WINNT=0x0A00
    )
    target_sources(foo.bar.examples.${example} PRIVATE ${example}.cpp)
    target_link_libraries(
            foo.bar.examples.${example}
            PRIVATE foo::bar
    )
endforeach ()

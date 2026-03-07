
set(ALL_EXAMPLES hello)

foreach(example ${ALL_EXAMPLES})
    add_executable(foo.bar.examples.${example})
    target_sources(foo.bar.examples.${example} PRIVATE ${example}.cpp)
    target_link_libraries(
            foo.bar.examples.${example}
            PRIVATE foo::bar
    )
endforeach()


function (set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endfunction()

function (set_choice var choice default message)
    if(NOT ${var})
        set(default_build_type ${default})
        message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
        set(${var} "${default_build_type}" CACHE STRING ${message} FORCE)
        set_property(CACHE ${var} PROPERTY STRINGS ${choice})
    endif()
endfunction()
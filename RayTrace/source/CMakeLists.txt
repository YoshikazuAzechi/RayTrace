
set(SRCS
    main.cpp
    image.cpp
    vector3.cpp
    color.cpp
    ray.cpp
    sphere.cpp
    ppm.cpp
    world.cpp
    object.cpp)

add_executable(${PROJECT_NAME} ${SRCS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

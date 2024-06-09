cmake_minimum_required(VERSION 3.16)

include(CPack)
set(CPACK_PACKAGE_NAME "glfwTest")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "hellovertex")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libglfw3, libpthread-stubs0-dev, libdl2, libgl1-mesa-glx, libx11-6")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

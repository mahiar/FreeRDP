# FreeRDP: A Remote Desktop Protocol Implementation
# FreeRDP Mac OS X Server cmake build script
#
# Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(MODULE_NAME "mfreerdp-server")
set(MODULE_PREFIX "FREERDP_SERVER_MAC")

set(${MODULE_PREFIX}_SRCS
	mfreerdp.c
	mfreerdp.h
	mf_audin.c
	mf_audin.h
	mf_rdpsnd.c
	mf_rdpsnd.h)

add_executable(${MODULE_NAME} ${${MODULE_PREFIX}_SRCS})

set(${MODULE_PREFIX}_LIBS ${${MODULE_PREFIX}_LIBS} freerdp-server)

set_complex_link_libraries(VARIABLE ${MODULE_PREFIX}_LIBS
	MONOLITHIC ${MONOLITHIC_BUILD}
	MODULE freerdp
	MODULES freerdp-core freerdp-utils freerdp-codec)
	
set_complex_link_libraries(VARIABLE ${MODULE_PREFIX}_LIBS
	MONOLITHIC ${MONOLITHIC_BUILD}
	MODULE winpr
	MODULES winpr-crt)

target_link_libraries(${MODULE_NAME} ${${MODULE_PREFIX}_LIBS})
install(TARGETS ${MODULE_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})

set_property(TARGET ${MODULE_NAME} PROPERTY FOLDER "Server/Mac")
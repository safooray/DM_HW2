#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1115151369/Itemset.o \
	${OBJECTDIR}/_ext/1115151369/Node.o \
	${OBJECTDIR}/_ext/1115151369/Trie.o \
	${OBJECTDIR}/_ext/1115151369/main.o \
	${OBJECTDIR}/_ext/1115151369/my_sort.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dm2

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dm2: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dm2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1115151369/Itemset.o: /Users/Ayine/NetBeansProjects/DM2/Itemset.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1115151369
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1115151369/Itemset.o /Users/Ayine/NetBeansProjects/DM2/Itemset.cpp

${OBJECTDIR}/_ext/1115151369/Node.o: /Users/Ayine/NetBeansProjects/DM2/Node.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1115151369
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1115151369/Node.o /Users/Ayine/NetBeansProjects/DM2/Node.cpp

${OBJECTDIR}/_ext/1115151369/Trie.o: /Users/Ayine/NetBeansProjects/DM2/Trie.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1115151369
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1115151369/Trie.o /Users/Ayine/NetBeansProjects/DM2/Trie.cpp

${OBJECTDIR}/_ext/1115151369/main.o: /Users/Ayine/NetBeansProjects/DM2/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1115151369
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1115151369/main.o /Users/Ayine/NetBeansProjects/DM2/main.cpp

${OBJECTDIR}/_ext/1115151369/my_sort.o: /Users/Ayine/NetBeansProjects/DM2/my_sort.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1115151369
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1115151369/my_sort.o /Users/Ayine/NetBeansProjects/DM2/my_sort.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dm2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

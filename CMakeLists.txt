# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

# Solution
project ("Arkanoid")

# Each sub-project
set(EXECUTABLE_CUSTOM_NAME "00-Starter")
add_subdirectory ("00-Starter")

set(EXECUTABLE_CUSTOM_NAME "Paintings")
add_subdirectory ("Paintings")

set(EXECUTABLE_CUSTOM_NAME "Arkanoid")
add_subdirectory ("Arkanoid")

set(EXECUTABLE_CUSTOM_NAME "SpaceShooter")
add_subdirectory ("SpaceShooter")

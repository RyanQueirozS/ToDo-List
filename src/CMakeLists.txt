file(GLOB srcfiles
  "./*.hpp"
  "./*cpp"
  )
add_library(src ${srcfiles})

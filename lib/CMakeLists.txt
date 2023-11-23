file(GLOB libfile
  "./*.hpp"
  "./*cpp"
  )
add_library(lib ${libfile})

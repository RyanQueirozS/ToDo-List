file(GLOB includefiles
     "./libconfig/lib/*.h++"
     "./libconfig/lib/*.c++"
     "./libconfig/lib/*.h"
     "./libconfig/lib/*.c"
)
add_library(include
  ${includefiles}
  )

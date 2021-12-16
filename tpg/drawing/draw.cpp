#include "draw.hpp"

template<typename Color>
void tpg::DrawingCanvas<Color>::render() {
  Canvas<Color>::render();
}

// Possible template values
#include "template_specs.hpp"

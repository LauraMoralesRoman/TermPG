#ifndef DRAWING_ENGINE_
#define DRAWING_ENGINE_

#include "../canvas/canvas.hpp"

namespace tpg {
  template<typename Color>
  class DrawingCanvas : public tpg::Canvas<Color> {
    public:

      void render();
    private:
  };
}

#endif

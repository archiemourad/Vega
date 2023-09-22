#pragma once
#include "../Util/Cast.h"

#include "Actors/Camera.h"

namespace Vega
{
	namespace Scene
	{
		class Scene
		{
		public:
			// Getters & Setters.

			Util::Cast<Actors::Camera>& GetCameras() { return cameras; }
			void SetCameras(Util::Cast<Actors::Camera> cameras) { this->cameras = cameras; }

		private:
			Util::Cast<Actors::Camera> cameras;

		};
	}
}


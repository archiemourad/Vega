#pragma once
#include "../Util/Cast.h"

#include "Actors/Camera.h"
#include "Actors/Object.h"

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

			Util::Cast<Actors::Object>& GetObjects() { return objects; }
			void SetObjects(Util::Cast<Actors::Object> objects) { this->objects = objects; }

		private:
			// Casts.

			Util::Cast<Actors::Camera> cameras;

			Util::Cast<Actors::Object> objects;

		};
	}
}


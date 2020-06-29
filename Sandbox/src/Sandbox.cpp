#include <Moist.h>

class Sandbox : public Moist::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

// Creates new Application
Moist::Application* Moist::CreateApplication() {
	return new Sandbox();
}
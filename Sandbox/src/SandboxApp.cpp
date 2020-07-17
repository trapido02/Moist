#include <Moist.h>

class ExampleLayer : public Moist::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}

	void OnUpdate() override {
		//MS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Moist::Event& event) override {
		MS_TRACE("{0}", event);
	}
};

class Sandbox : public Moist::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Moist::ImGuiLayer());
	}

	~Sandbox() {

	}
};

// Creates new Application
Moist::Application* Moist::CreateApplication() {
	return new Sandbox();
}
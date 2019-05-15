#pragma once
#include "Test.h"
///#include "GL/glew.h"
///#include "Renderer.h"

namespace test {
	
	
	class TestClearColor : public Test
	{
		public:
			TestClearColor();
			~TestClearColor();
		public://Methods
			void OnUpdate(float deltaTime) override;
			void OnRender() override;
			void OnImGuiRender() override;
		
		private://Members
			float m_ClearColor[4];
		
	};

}

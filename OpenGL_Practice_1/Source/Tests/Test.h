#pragma once

namespace test {

	class Test
	{
		
		public:
			Test() {}
			~Test() {}
			
		public://Methods
			virtual void OnUpdate(float deltaTime) {}
			virtual void OnRender() {}
			virtual void OnImGuiRender() {}
		
		private://Methods
		
		private://Members
	};

}

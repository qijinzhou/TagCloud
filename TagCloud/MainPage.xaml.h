//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace TagCloud
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void Canvas_Draw(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs^ args);
	};
}

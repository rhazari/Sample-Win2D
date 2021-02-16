//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace SampleWin2D
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void Click_Me(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		//void OnSizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventHandler^ e);
		void OnRegionsInvalidated(Microsoft::Graphics::Canvas::UI::Xaml::CanvasVirtualControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasRegionsInvalidatedEventArgs^ args);
		
		Microsoft::Graphics::Canvas::UI::Xaml::CanvasVirtualControl^ control_;
	};
}

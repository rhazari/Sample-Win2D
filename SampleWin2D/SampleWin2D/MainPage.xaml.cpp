//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace SampleWin2D;

using namespace Platform;
using namespace Windows::UI;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

using namespace Microsoft::Graphics::Canvas::UI::Xaml;
using namespace Microsoft::Graphics::Canvas::Geometry;
using namespace Windows::System::Threading;
using namespace Windows::Foundation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}

void SampleWin2D::MainPage::Click_Me(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) {
    control_ = ref new CanvasVirtualControl();
	control_->RegionsInvalidated += ref new Windows::Foundation::TypedEventHandler<Microsoft::Graphics::Canvas::UI::Xaml::CanvasVirtualControl^, Microsoft::Graphics::Canvas::UI::Xaml::CanvasRegionsInvalidatedEventArgs^>(this, &SampleWin2D::MainPage::OnRegionsInvalidated);
	control_->SizeChanged += ref new Windows::UI::Xaml::SizeChangedEventHandler(this, &SampleWin2D::MainPage::OnSizeChanged);
    
    // Create a single-shot timer
    // https://docs.microsoft.com/en-us/windows/uwp/threading-async/use-a-timer-to-submit-a-work-item
    TimeSpan delay;
    delay.Duration = 1000000000 / 20;     // Approx about 5 secs
    ThreadPoolTimer^ delayTimer = ThreadPoolTimer::CreateTimer(ref new TimerElapsedHandler([this](ThreadPoolTimer^) {
        Dispatcher->RunAsync(CoreDispatcherPriority::High, ref new DispatchedHandler([this]() {
            control_->Width = 1000;
            control_->Height = 1000;
            MyCanvas->Children->Append(control_);
            MyCanvas->SetLeft(control_, 0);
            MyCanvas->SetTop(control_, 0);
        }));
    }), delay);
}

void SampleWin2D::MainPage::OnSizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ args) {
	control_->Invalidate();
}

void SampleWin2D::MainPage::OnRegionsInvalidated(Microsoft::Graphics::Canvas::UI::Xaml::CanvasVirtualControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasRegionsInvalidatedEventArgs^ args) {
	auto rectangle = CanvasGeometry::CreateRectangle(sender, 10, 10, 100, 100);
	for (const auto& region : args->InvalidatedRegions) {
		if (auto drawingSession = sender->CreateDrawingSession(region)) {
			drawingSession->FillGeometry(rectangle, Colors::Blue);
		}
	}
}
//
// App.xaml.h
// Declaration of the App class.
//

#pragma once

#include "App.g.h"

namespace SampleWin2D
{
	/// <summary>
	/// Provides application-specific behavior to supplement the default Application class.
	/// </summary>
	ref class App sealed
	{
	protected:
		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) override;

	internal:
		App();

	private:
		void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);
		void onEnteringBackground(Platform::Object^, Windows::ApplicationModel::EnteredBackgroundEventArgs^);
		void onLeavingBackground(Platform::Object^, Windows::ApplicationModel::LeavingBackgroundEventArgs^);
		void OnNavigationFailed(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs ^e);

		bool enteredBackground_ = false;
	};
}

//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "CanvasRenderer.h"
#include "SampleTexts.h"
#include "Tag.h"
#include "TagCloudLayout.h"

using namespace TagCloud;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace Microsoft::Graphics::Canvas::UI::Xaml;

MainPage::MainPage()
{
	InitializeComponent();
}

void TagCloud::MainPage::Canvas_Draw(CanvasControl^ sender, CanvasDrawEventArgs^ args)
{
	TagCollection collection = SampleTexts::GetSample1();
	TagCloudLayout layout(sender);
	layout.Layout(collection);

	CanvasRenderer renderer(args->DrawingSession);
	layout.Render(renderer);
}

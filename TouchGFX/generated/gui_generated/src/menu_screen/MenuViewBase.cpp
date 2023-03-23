/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/menu_screen/MenuViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

MenuViewBase::MenuViewBase() :
    frameCountFadeOutInterval(0),
    buttonCallback(this, &MenuViewBase::buttonCallbackHandler),
    fadeOutEndedCallback(this, &MenuViewBase::fadeOutEndedCallbackHandler)
{

    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    background1.setXY(0, 0);
    background1.setBitmap(touchgfx::Bitmap(BITMAP_TRACK4_ID));

    changescreen.setXY(35, 220);
    changescreen.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    changescreen.setLabelText(touchgfx::TypedText(T_START));
    changescreen.setLabelColor(touchgfx::Color::getColorFromRGB(247, 0, 0));
    changescreen.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 0, 0));
    changescreen.setAction(buttonCallback);

    car.setBitmap(touchgfx::Bitmap(BITMAP_REDCAR_ID));
    car.setPosition(102, 80, 37, 53);
    car.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);

    textArea2.setXY(49, 36);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NDXU));

    textArea1.setXY(21, 10);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_FA8E));

    carName.setXY(99, 133);
    carName.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    carName.setLinespacing(0);
    carName.setTypedText(touchgfx::TypedText(T___SINGLEUSE_U660));

    HP.setXY(35, 160);
    HP.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    HP.setLinespacing(0);
    HP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TGXE));

    SPD.setXY(99, 160);
    SPD.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    SPD.setLinespacing(0);
    SPD.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W5EX));

    BUL.setXY(161, 160);
    BUL.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    BUL.setLinespacing(0);
    BUL.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NKCG));

    add(__background);
    add(background1);
    add(changescreen);
    add(car);
    add(textArea2);
    add(textArea1);
    add(carName);
    add(HP);
    add(SPD);
    add(BUL);
}

void MenuViewBase::setupScreen()
{

}

//Handles tick based events
void MenuViewBase::handleTickEvent()
{
    frameCountFadeOutInterval++;
    if(frameCountFadeOutInterval == TICK_FADEOUT_INTERVAL)
    {
        //FadeOut
        //When every N tick fade textArea1
        //Fade textArea1 to alpha:255 with LinearInOut easing in 500 ms (30 Ticks)
        textArea1.clearFadeAnimationEndedAction();
        textArea1.startFadeAnimation(255, 30, touchgfx::EasingEquations::linearEaseInOut);
        textArea1.setFadeAnimationEndedAction(fadeOutEndedCallback);
        frameCountFadeOutInterval = 0;
    }

}

void MenuViewBase::fadeOutEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::TextArea>& comp)
{

}

void MenuViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &changescreen)
    {
        //changeScreen
        //When changescreen clicked change screen to Screen1
        //Go to Screen1 with no screen transition
        application().gotoScreen1ScreenNoTransition();

        //Interaction1
        //When changescreen clicked execute C++ code
        //Execute C++ code
        extern osMessageQueueId_t Queue2Handle;	
        extern int32_t curCar;
        uint32_t count_2=osMessageQueueGetCount(Queue2Handle);
        	if (count_2 < 2) {
        		int32_t x = curCar;
        		osMessageQueuePut(Queue2Handle,&x,0,10);
        	}
    }
}

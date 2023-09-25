#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include <string>
#include <iostream>

namespace Chotra_RT {

    class Application {

    public:
        Application();
        virtual ~Application();

        Application(const Application&) = delete;
        Application(Application&&) = delete;

        Application& operator=(const Application&) = delete;
        Application& operator=(Application&&) = delete;

        virtual int Start();
        //virtual void OnUpdate(float deltaTime);


    private:


        float currentTime = 0.0f;
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;


    };
} // namespace Chotra_RT

#endif;


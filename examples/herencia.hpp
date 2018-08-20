#ifndef __EXAMPLES_HERENCIA_HPP__
#define __EXAMPLES_HERENCIA_HPP__

#include <functional>
#include <iostream>

class StatefulApp
{
protected:
    size_t m_id;
    enum class State
    {
        CREATED,
        STARTED,
        LAUNCHED,
        RUNNING,
        FINISHED,
        STOPED
    };
    State m_state;
public:
    StatefulApp() :
        m_id
        (
            std::hash<int64_t >()(reinterpret_cast<int64_t >(this))
        ),
        m_state(State::CREATED)
    {

    }
    virtual void start  () {std::cout << "Starting  app with id: " << m_id << std::endl;}
    virtual void launch () {std::cout << "Launching app with id: " << m_id << std::endl;}
    virtual void run    () {std::cout << "Running   app with id: " << m_id << std::endl;}
    virtual void stop   () {std::cout << "Stopping  app with id: " << m_id << std::endl;}

    State get_state(){return m_state;}
};


class LimitRunApp : public StatefulApp
{
protected:
    unsigned int m_times_runned;
    unsigned int m_run_limit;
public:
    LimitRunApp(unsigned int limit = 100) :
        m_times_runned  (0),
        m_run_limit     (limit)
    {

    }
    void start () override {m_state = State::STARTED;  StatefulApp::start();}
    void launch() override {if(m_state == State::STARTED) {m_state = State::LAUNCHED; StatefulApp::launch();}}
    void run   () override
    {
        if      (m_state == State::LAUNCHED) m_state = State::RUNNING;
        else if (m_state == State::RUNNING)
        {
            StatefulApp::run();
            m_times_runned += 1;
            std::cout << "App run times: " << m_times_runned << std::endl;
            if(m_times_runned == m_run_limit) m_state = State::FINISHED;
        }
        else return;
    }
    void stop () override {if(m_state == State::FINISHED){ m_state = State::STOPED; StatefulApp::stop();}}
    static void run_test_app()
    {
        LimitRunApp app;
        app.start();
        app.launch();
        while (app.get_state() != State::FINISHED)
            app.run();
        app.stop();
    }
};



class A
{
public:
    A(int val = 0):m_value(val){}
    friend class B;
    int get_val() const {return m_value;}
private:
    int m_value;
};

class B
{
public:
    A m_fiend;

    B() : m_fiend(10) {}
    void add_one_to_friend() {m_fiend.m_value += 1;}

};

void test_friends()
{
    A a;
    //a.m_value = 10;//ERROR cannot acces
    B b;
    std::cout << "A within B value: " << b.m_fiend.get_val() << std::endl;
    b.add_one_to_friend();
    std::cout << "B acces A and modifies its private value: " << b.m_fiend.get_val() << std::endl;
}

#endif //EXAMPLES_HERENCIA_HPP

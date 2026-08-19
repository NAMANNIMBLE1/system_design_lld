#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

//****************************************** abstract classes *************************************** */

class WalkableRobot{
    public:
        virtual void walk() = 0;
        virtual ~WalkableRobot(){}
};

class NormalWalk:public WalkableRobot{
    public:
        void walk() override{
            cout<<"robot walks normal"<<endl;
        }
};

class NoWalk:public WalkableRobot{
    public:
        void walk() override{
            cout<<"robot does not walk"<<endl;
        }
};



class TalkableRobot{
    public:
        virtual void talk() = 0;
        virtual ~TalkableRobot(){};
};      


class NormalTalk:public TalkableRobot{
    public:
        void talk() override{
            cout<<"robot talk normal"<<endl;
        }
};

class NoTalkableRobot:public TalkableRobot{
    public:
        void talk() override{
            cout<<"robot does not talk"<<endl;
        }
};



class FlyableRobot{
    public:
        virtual void fly() = 0; 

        virtual ~FlyableRobot(){};
};


class NormalFlyRobot:public FlyableRobot{
    public:
        void fly() override{
            cout<<"robot fly normally"<<endl;
        }
};

class NoFlyRobot:public FlyableRobot{
    public:
        void fly() override{
            cout<<"robot does not fly"<<endl;
        }
};

class FlyWithJettRobot:public FlyableRobot{
    public:
        void fly() override{
            cout<<"robot fly using jett engine"<<endl;
        }
};


//************************************************** robot base class ******************************** */

class Robot{
    protected:
        TalkableRobot* talkbehaviour;
        WalkableRobot* walkbehaviour;
        FlyableRobot* flybehaviour;
    
    public:
        // constructor
        Robot(WalkableRobot* w , TalkableRobot* t , FlyableRobot* f){
            this->talkbehaviour = t;
            this->walkbehaviour = w;
            this->flybehaviour = f;
        }

    void walk(){
        walkbehaviour->walk();
    }

    void talk(){
        talkbehaviour->talk();
    }

    void fly(){
        flybehaviour->fly();
    }

    virtual void projection() = 0; //abstract method for diff types of robot
};


//****************************** types of robot ********************************************** */

class CompanionRobot : public Robot{
    public:
        // constructor
        CompanionRobot() : Robot(new NormalWalk , new NormalTalk , new NoFlyRobot){}

        void projection() override{
            cout<<"displaying companion robot features..."<<endl;
        }
};


class WorkerRobot: public Robot{
    public:
        // constructor
        WorkerRobot():Robot(new NormalWalk(), new NoTalkableRobot(), new NoFlyRobot()){}
        
        void projection() override{
            cout<<"displaying worker efficiency stats..."<<endl;
        }
};

class jettrobot: public Robot{
    public:
        // constructor
        jettrobot():Robot(new NormalWalk(), new NoTalkableRobot(), new FlyWithJettRobot()){}
        
        void projection() override{
            cout<<"displaying worker efficiency stats..."<<endl;
        }
};




int main(){
    
    Robot* companion = new CompanionRobot();

    companion->walk();
    companion->talk();
    companion->fly();
    companion->projection();

    cout << endl;

    Robot* worker = new WorkerRobot();

    worker->walk();
    worker->talk();
    worker->fly();
    worker->projection();

    cout << endl;

    Robot* jett_robot = new jettrobot();

    jett_robot->walk();
    jett_robot->talk();
    jett_robot->fly();
    jett_robot->projection();

    delete companion;
    delete worker;
    delete jett_robot;

    return 0;
}
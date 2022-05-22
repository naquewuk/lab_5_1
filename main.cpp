#include <iostream>
#include <string>
#include <stdexcept>

class Airplane{
public:

    Airplane();
    Airplane(std::string m_Brand, std::string m_Model, int m_MaxSpeed, int m_MaxHeight);

    std::string getBrand() const { return Brand; }

    std::string getModel() const { return Model; }

    int getMaxSpeed() const { return MaxSpeed; }

    int getMaxHeight() const { return MaxHeight; }

    void setBrand(std::string tmp_brand){ Brand = tmp_brand;}

    void setModel(std::string tmp_model){ Model = tmp_model; }

    void setMaxSpeed(int tmp_maxspeed){ MaxSpeed = tmp_maxspeed;}

    void setMaxHeight(int tmp_maxheight){ MaxHeight = tmp_maxheight; }

    virtual std::string Info() const {
        return "Airplane: "    + Brand  + " - "   + Model + "\n"
               "Max Speed of " + Brand  + ": "  + std::to_string(MaxSpeed) + "\n"
               "Max flight altitude of " + Brand + ": " + std::to_string(MaxHeight) + "\n"
               "Price: " + std::to_string(Price());
    }

    virtual int Price() const { return (MaxSpeed * 1000) + (MaxHeight * 100); }

private:
    std::string Brand;
    std::string Model;
    int MaxSpeed;
    int MaxHeight;
};

Airplane::Airplane() :
        Brand("British Aircraft Corporation"), Model("Vickers VC10"), MaxSpeed(1000), MaxHeight(9000)
{}

Airplane::Airplane(std::string m_Brand, std::string m_Model, int m_MaxSpeed, int m_MaxHeight) :
        Brand(m_Brand), Model(m_Model), MaxSpeed(m_MaxSpeed), MaxHeight(m_MaxHeight)
{
    if(m_MaxSpeed <= 200){
        throw std::invalid_argument("Wrong max speed for Airplane. Please, try again.");
    }

    if(m_MaxHeight <= 1000){
        throw std::invalid_argument("Wromg Max flight altitude. Please, try again");
    }
}

class Bomber : public Airplane{
public:
    Bomber();
    Bomber(std::string m_Brand, std::string m_Model, int m_MaxSpeed, int m_MaxHeight);

    int Price() const override { return Airplane::Price() * 2; }

    std::string Info() const override{
        return "Airplane: " + Airplane::getBrand()  + " - "   + Airplane::getModel() + "\n"
               "Max Speed of " + Airplane::getBrand()  + ": "  + std::to_string(Airplane::getMaxSpeed()) + "\n"
               "Max flight altitude of " + Airplane::getBrand() + ": " + std::to_string(Airplane::getMaxHeight()) + "\n"
               "Price: " + std::to_string(Price());
    }

};

Bomber::Bomber() :
        Airplane("Ty", "160", 2200, 18000 )
{};


Bomber::Bomber(std::string m_Brand, std::string m_Model, int m_MaxSpeed, int m_MaxHeight) :
        Airplane(m_Brand, m_Model, m_MaxSpeed, m_MaxHeight)
{};


class Fighter : public Airplane{
public:
    Fighter();
    Fighter(std::string m_Brand, std::string m_Model, int m_MaxSpeed, int m_MaxHeight);

    int Price() const override{ return Airplane::Price() * 3; }

    std::string Info() const override{
        return "Airplane: " + Airplane::getBrand()  + " - "   + Airplane::getModel() + "\n"
               "Max Speed of " + Airplane::getBrand()  + ": "  + std::to_string(Airplane::getMaxSpeed()) + "\n"
               "Max flight altitude of " + Airplane::getBrand() + ": " + std::to_string(Airplane::getMaxHeight()) + "\n"
               "Price: " + std::to_string(Price());
    }
};

Fighter::Fighter() :
        Airplane("Cy", "27", 2500, 18500)
{};

Fighter::Fighter(std::string m_Brand, std::string m_Model, int m_MaxSpeed, int m_MaxHeight) :
        Airplane(m_Brand, m_Model, m_MaxSpeed, m_MaxHeight)

{};

int main(){
    std::string Brand, Model;
    int MaxSpeed, MaxHeight;
    int num;

    Airplane airplane;
    Bomber bomber;
    Fighter fighter;

    while(true){

        std::cout << "Choose the object to create:" << "\n"
                  << "1. Airplane." << "\n"
                  << "2. Bomber." << "\n"
                  << "3. Fighter." << "\n"
                  << "0. Exit." << "\n"
                  << "Enter number: ";

        std::cin >> num;
        system( "cls");

        try {
            bool exit = false;

            switch (num) {
                case 1:
                    std::cout << "You choose Airplane." << "\n"
                              << "Enter Airplane Brand: ";
                    std::cin >> Brand;
                    airplane.setBrand(Brand);
                    std::cout << "OK. Now enter model of airplane: ";
                    std::cin >> Model;
                    airplane.setModel(Model);
                    std::cout << "Enter airplane max speed: ";
                    std::cin >> MaxSpeed;
                    airplane.setMaxSpeed(MaxSpeed);
                    std::cout << "And now enter max flight altitude: ";
                    std::cin >> MaxHeight;
                    airplane.setMaxHeight(MaxHeight);
                    std::cout << airplane.Info() << std::endl;

                    break;

                case 2:
                    std::cout << "You choose Bomber." << "\n"
                              << "Enter Bomber Brand: ";
                    std::cin >> Brand;
                    bomber.setBrand(Brand);
                    std::cout << "Enter model of bomber: ";
                    std::cin >> Model;
                    bomber.setModel(Model);
                    std::cout << "Enter bomber max speed: ";
                    std::cin >> MaxSpeed;
                    bomber.setMaxSpeed(MaxSpeed);
                    std::cout << "And the last. Enter max flight altitude: ";
                    std::cin >> MaxHeight;
                    bomber.setMaxHeight(MaxHeight);
                    std::cout << bomber.Info() << std::endl;

                    break;

                case 3:
                    std::cout << "You choose Fighter." << "\n"
                              << "Enter Fighter Brand: ";
                    std::cin >> Brand;
                    fighter.setBrand(Brand);
                    std::cout << "Enter model of fighter: ";
                    std::cin >> Model;
                    fighter.setModel(Model);
                    std::cout << "Enter fighter max speed: ";
                    std::cin >> MaxSpeed;
                    fighter.setMaxSpeed(MaxSpeed);
                    std::cout << "Enter max flight atlitude: ";
                    std::cin >> MaxHeight;
                    fighter.setMaxHeight(MaxHeight);
                    std::cout << fighter.Info() << std::endl;

                    break;

                case 0:
                    exit = true;
                    break;

                default :
                    break;
            }

            if(exit == true) break;

        } catch (const std::exception& ex){
            std::cerr << ex.what() << std::endl;
        }
    }
}
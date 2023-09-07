
#pragma once

class Monster;
class Munchkin;

class Victory
{
public:
    virtual ~Victory() = default;
    virtual void apply(Monster*, Munchkin*) = 0;
};

class VictoryAdditionalCards : public Victory
{
    void apply(Monster*, Munchkin*) override;
};

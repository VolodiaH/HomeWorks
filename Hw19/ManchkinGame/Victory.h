
#pragma once

class Monster;

class Victory
{
public:
    virtual ~Victory() = default;
    virtual int apply(Monster*) = 0;
};

class VictoryAdditionalCards : public Victory
{
    int apply(Monster*) override;
};

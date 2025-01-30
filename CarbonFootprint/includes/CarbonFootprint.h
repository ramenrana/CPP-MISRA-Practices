/* 12.15 ( CarbonFootprint Abstract Class: Polymorphism) Using
an abstract class with only pure virtual functions, you can
specify similar behaviors for possibly disparate classes.
Governments and companies worldwide are becoming
increasingly concerned with carbon footprints (annual releases
of carbon dioxide into the atmosphere) from buildings burning
various types of fuels for heat, vehicles burning fuels for power,
and the like. Many scientists blame these greenhouse gases for
the phenomenon called global warming. Create three small
classes unrelated by inheritance—classes Building , Car and
Bicycle . Give each class some unique appropriate attributes
and behaviors that it does not have in common with other
classes. Write an abstract class CarbonFootprint with only a
pure virtual getCarbonFootprint member function. Have each of
your classes inherit from that abstract class and implement the
getCarbonFootprint member function to calculate an appropriate
carbon footprint for that class (check out a few websites that
explain how to calculate carbon footprints). Write an application
that creates objects of each of the three classes, places
pointers to those objects in a vector of CarbonFootprint
pointers, then iterates through the vector , polymorphically
invoking each object’s getCarbonFootprint member function.
For each object, print some identifying information and the
object’s carbon footprint.
*/
#ifndef CARBONFOOTPRINT_H
#define CARBONFOOTPRINT_H

class CarbonFootprint
{
private:
    double NoOfCarbonFootprint;
public:
    CarbonFootprint();
    virtual ~CarbonFootprint() = default;
    virtual double getCarbonFootprint() const = 0;
};



#endif // CARBONFOOTPRINT_H

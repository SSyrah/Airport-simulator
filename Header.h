#pragma once
#include "Utility.h"
#include "RANDOM.H"

enum Runway_activity
{
    idle,
    land,
    take_off,
    drop
};
enum Plane_status
{
    null,
    arriving,
    departing
};
void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate);
void run_idle(int time);


const int maxqueue = 100; //  small value for testing

class Plane
{
public:
    Plane();
    Plane(int flt, int time, Plane_status status);
    void refuse() const;
    void land(int time) const;
    void fly(int time) const;
    int started() const;
    void random_fuel();
    void decrease_fuel();
    int get_fuel() const;
    void drop(int time) const;
    

private:
    int flt_num;
    int clock_start;
    Plane_status state;
    int fuel{1};
};

typedef Plane Queue_entry;

class Queue
{
public:
    Queue();
    bool empty() const;
    Error_code serve();
    Error_code append(const Queue_entry &item);
    Error_code retrieve(Queue_entry &item) const;

protected:
    int count;
    int front, rear;
    Queue_entry entry[maxqueue];
};

class Extended_queue : public Queue
{
public:
    bool full() const;
    int size() const;
    void clear();
};

class Runway
{
public:
    Runway(int limit);
    Error_code can_land(const Plane &current);
    Error_code can_depart(const Plane &current);
    Runway_activity activity(int time, Plane &moving);
    Runway_activity activity2(int time, Plane &moving);
    void shut_down(int time) const;
    void short_shut_down(int time) const;

    bool is_takeoff_empty();
    bool is_landing_empty();
    bool is_takeoff_full();
    bool is_landing_full();
    void add_landing();
    void add_takeoff();
    int get_landing_size() const;
    int get_takeoff_size() const;
    void add_drop();
    bool check_fuel_rate(Plane& plane, int fuel_rate);

private:
    Extended_queue landing;
    Extended_queue takeoff;
    int queue_limit;
    int num_land_requests;    //  number of planes asking to land
    int num_takeoff_requests; //  number of planes asking to take off
    int num_landings;         //  number of planes that have landed
    int num_takeoffs;         //  number of planes that have taken off
    int num_land_accepted;    //  number of planes queued to land
    int num_takeoff_accepted; //  number of planes queued to take off
    int num_land_refused;     //  number of landing planes refused
    int num_takeoff_refused;  //  number of departing planes refused
    int land_wait;            //  total time of planes waiting to land
    int takeoff_wait;         //  total time of planes waiting to take off
    int idle_time;            //  total time runway is idle
    int num_dropped{};          //  total amount of dropped planes
};

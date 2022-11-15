// Datastructures.hh
//
// Student name: Eppu Hassinen
// Student email: eppu.hassinen@tuni.fi
// Student number: 50044786

#ifndef DATASTRUCTURES_HH
#define DATASTRUCTURES_HH

#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <limits>
#include <functional>
#include <exception>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>


// Types for IDs
using StationID = std::string;
using TrainID = std::string;
using RegionID = unsigned long long int;
using Name = std::string;
using Time = unsigned short int;

// Return values for cases where required thing was not found
StationID const NO_STATION = "---";
TrainID const NO_TRAIN = "---";
RegionID const NO_REGION = -1;
Name const NO_NAME = "!NO_NAME!";
Time const NO_TIME = 9999;

// Return value for cases where integer values were not found
int const NO_VALUE = std::numeric_limits<int>::min();


// Type for a coordinate (x, y)
struct Coord
{
    int x = NO_VALUE;
    int y = NO_VALUE;
};

// Example: Defining == and hash function for Coord so that it can be used
// as key for std::unordered_map/set, if needed
inline bool operator==(Coord c1, Coord c2) { return c1.x == c2.x && c1.y == c2.y; }
inline bool operator!=(Coord c1, Coord c2) { return !(c1==c2); } // Not strictly necessary
inline bool operator<(Coord c1, Coord c2)
{
    float d1 = std::sqrt(pow(c1.x,2) + pow(c1.y,2));
    float d2 = std::sqrt(pow(c2.x,2) + pow(c2.y,2));
    return d1 < d2 or (d1 == d2 and c1.y < c2.y);
}


struct CoordHash
{
    std::size_t operator()(Coord xy) const
    {
        auto hasher = std::hash<int>();
        auto xhash = hasher(xy.x);
        auto yhash = hasher(xy.y);
        // Combine hash values (magic!)
        return xhash ^ (yhash + 0x9e3779b9 + (xhash << 6) + (xhash >> 2));
    }
};

struct station
{
    StationID id;
    Name name;
    Coord coord;
    std::map<TrainID,Time> trains;
    RegionID parent = NO_REGION;

};

struct region
{
    RegionID id;
    Name name = "";
    region* parent = nullptr;
    std::set<region*> subregions = {};
    std::set<station*> stations = {};
    std::vector<Coord> coords = {};

};



// Return value for cases where coordinates were not found
Coord const NO_COORD = {NO_VALUE, NO_VALUE};

// Type for a distance (in metres)
using Distance = int;

// Return value for cases where Distance is unknown
Distance const NO_DISTANCE = NO_VALUE;

// This exception class is there just so that the user interface can notify
// about operations which are not (yet) implemented
class NotImplemented : public std::exception
{
public:
    NotImplemented() : msg_{} {}
    explicit NotImplemented(std::string const& msg) : msg_{msg + " not implemented"} {}

    virtual const char* what() const noexcept override
    {
        return msg_.c_str();
    }
private:
    std::string msg_;
};


// This is the class you are supposed to implement

class Datastructures
{
public:
    Datastructures();
    ~Datastructures();

    // Estimate of performance: O(1)
    // Short rationale for estimate: map.empty and map.size are constant operations
    unsigned int station_count();

    // Estimate of performance: O(n)
    // Short rationale for estimate: map.clear is linear and the function doesn't do
    // anything else
    void clear_all();

    // Estimate of performance: O(n)
    // Short rationale for estimate: function inserts n times to vector and
    // inserting to a vector is constant
    std::vector<StationID> all_stations();

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: find and insert in map are O(log(n))
    // O(2log(n)) = O(log(n))
    bool add_station(StationID id, Name const& name, Coord xy);

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: find and accessing are O(log(n))
    // and the function does that
    Name get_station_name(StationID id);

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: find and accessing are O(log(n))
    // and the function does that
    Coord get_station_coordinates(StationID id);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: O(n log(n))
    // Short rationale for estimate: sorting is O(n log(n))
    // and O(3n log(n)) = O(n log(n))
    std::vector<StationID> stations_alphabetically();

    // Estimate of performance: O(n log(n))
    // Short rationale for estimate: sorting is O(n log(n))
    // and O(3n log(n)) = O(n log(n))
    std::vector<StationID> stations_distance_increasing();

    // Estimate of performance: O(n)
    // Short rationale for estimate: loops through all stations and
    // returns before if coordinate is found
    StationID find_station_with_coord(Coord xy);

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: finding and inserting value in map are
    // asymptotic efficiency is log(n)
    bool change_station_coord(StationID id, Coord newcoord);

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: 3 log(n) = log(N) and the asymptotic efficiency is just that
    bool add_departure(StationID stationid, TrainID trainid, Time time);

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: all operations are O(log(n)) so the overall
    // efficiency is O(log(n))
    bool remove_departure(StationID stationid, TrainID trainid, Time time);

    // Estimate of performance: O(n log(n))
    // Short rationale for estimate: function is kind of bad but works
    // The efficiency is my biggest consern.
    std::vector<std::pair<Time, TrainID>> station_departures_after(StationID stationid, Time time);

    // We recommend you implement the operations below only after implementing the ones above

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: find and insert in map are O(log(n))
    // O(2log(n)) = O(log(n))
    bool add_region(RegionID id, Name const& name, std::vector<Coord> coords);

    // Estimate of performance: O(n)
    // Short rationale for estimate: loops through all elements and the
    // efficiency of the function is O(n)
    std::vector<RegionID> all_regions();

    // Estimate of performance: O(log (n))
    // Short rationale for estimate: finding in a map is O(log(n))
    // so the overall efficiency is the same
    Name get_region_name(RegionID id);

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: finding in a map is O(log(n))
    // so the overall efficiency is the same
    std::vector<Coord> get_region_coords(RegionID id);

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: finding and insertion are O(log(n))
    // so the overall efficiency is O(log(n))
    bool add_subregion_to_region(RegionID id, RegionID parentid);

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: finding and insertion are O(log(n))
    // so the overall efficiency is O(log(n))
    bool add_station_to_region(StationID id, RegionID parentid);

    // Estimate of performance: O(n log(n))
    // Short rationale for estimate: worst case is if all regions
    // are subregions to eachother. In most cases it is faster
    std::vector<RegionID> station_in_regions(StationID id);

    // Non-compulsory operations

    // Estimate of performance: O(log(n) + n)
    // Short rationale for estimate: finding is O(log(n)) and
    // insertion is O(n) so the overall efficiency is O(log(n) + n)
    std::vector<RegionID> all_subregions_of_region(RegionID id);

    // Estimate of performance: O(n log(n))
    // Short rationale for estimate: sorting is O(n log(n)) and the other
    // operations are constant
    std::vector<StationID> stations_closest_to(Coord xy);

    // Estimate of performance: O(log(n))
    // Short rationale for estimate: finding and erasing from a map are O(log(n))
    // so the overall efficiency is O(log(n))
    bool remove_station(StationID id);

    // Estimate of performance: O(n log(n))
    // Short rationale for estimate: finding is O(log(n)) and looping through is O(n)
    RegionID common_parent_of_regions(RegionID id1, RegionID id2);

private:
    // Add stuff needed for your class implementation here

    std::map<StationID,station> station_map_;

    std::map<RegionID, region> region_map_;

    void rec_subregions_of_region(std::vector<RegionID> &subregions,region* current_region);

};

#endif // DATASTRUCTURES_HH

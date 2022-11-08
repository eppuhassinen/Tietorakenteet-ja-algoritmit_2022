// Datastructures.cc
//
// Student name: Eppu Hassinen
// Student email: eppu.hassinen@tuni.fi
// Student number: 50044786

#include "datastructures.hh"

#include <random>

#include <cmath>

std::minstd_rand rand_engine; // Reasonably quick pseudo-random generator

template <typename Type>
Type random_in_range(Type start, Type end)
{
    auto range = end-start;
    ++range;

    auto num = std::uniform_int_distribution<unsigned long int>(0, range-1)(rand_engine);

    return static_cast<Type>(start+num);
}

// Modify the code below to implement the functionality of the class.
// Also remove comments from the parameter names when you implement
// an operation (Commenting out parameter name prevents compiler from
// warning about unused parameters on operations you haven't yet implemented.)

Datastructures::Datastructures()
{
    // Write any initialization you need here
    station_map_ = {};
}

Datastructures::~Datastructures()
{
    // Write any cleanup you need here
}

unsigned int Datastructures::station_count()
{
    // Replace the line below with your implementation
    if ( station_map_.empty() ) {return 0;}

    return station_map_.size();
}

void Datastructures::clear_all()
{
    // Replace the line below with your implementation
    station_map_.clear();

}

std::vector<StationID> Datastructures::all_stations()
{
    // Replace the line below with your implementation
    std::vector<StationID> all_station_ids = {};

    for ( auto &stat : station_map_ )
    {
        all_station_ids.push_back(stat.second.id);
    }

    return all_station_ids;
}

bool Datastructures::add_station(StationID id, const Name& name, Coord xy)
{
    // Replace the line below with your implementation
    if ( station_map_.find(id) != station_map_.end() ) { return false; }

    station new_station;
    new_station.id = id;
    new_station.name = name;
    new_station.coord = xy;

    station_map_[id] = (new_station);
    return true;
}

Name Datastructures::get_station_name(StationID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )

    if ( station_map_.find(id) == station_map_.end() ) { return NO_NAME; }

    return station_map_.at(id).name;

}

Coord Datastructures::get_station_coordinates(StationID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    if ( station_map_.find(id) == station_map_.end() ) { return NO_COORD; }

    return station_map_.at(id).coord;

}

std::vector<StationID> Datastructures::stations_alphabetically()
{
    // Replace the line below with your implementation
    if ( station_map_.empty() ) {return {};}
    std::vector<StationID> alphabetic = {};

    std::vector<station> stations = {};
    for (auto &stat : station_map_)
    {
        stations.push_back(stat.second);
    }


    sort(stations.begin(), stations.end(), [&](station i, station j) {return i.name < j.name;});

    for (auto &stat : stations)
    {
        alphabetic.push_back(stat.id);
    }

    return alphabetic;
}

std::vector<StationID> Datastructures::stations_distance_increasing()
{
    // Replace the line below with your implementation
    if ( station_map_.empty() ) {return {};}
    std::vector<StationID> distances = {};
    std::vector<station> stations = {};
    for (auto &stat : station_map_)
    {
        stations.push_back(stat.second);
    }


    sort(stations.begin(), stations.end(), [&](station i, station j) {return i.coord < j.coord;});

    for (auto &stat : stations)
    {
        distances.push_back(stat.id);
    }

    return distances;
}

StationID Datastructures::find_station_with_coord(Coord xy)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    for (auto &stat : station_map_)
    {
        if ( stat.second.coord == xy ) { return stat.first; }
    }

    return NO_STATION;
}

bool Datastructures::change_station_coord(StationID id, Coord newcoord)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    if ( station_map_.find(id) == station_map_.end() ) {return false;}

    station_map_[id].coord = newcoord;
    return true;
}

bool Datastructures::add_departure(StationID /*stationid*/, TrainID /*trainid*/, Time /*time*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("add_departure()");
}

bool Datastructures::remove_departure(StationID /*stationid*/, TrainID /*trainid*/, Time /*time*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("remove_departure()");
}

std::vector<std::pair<Time, TrainID>> Datastructures::station_departures_after(StationID /*stationid*/, Time /*time*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("station_departures_after()");
}

bool Datastructures::add_region(RegionID /*id*/, const Name &/*name*/, std::vector<Coord> /*coords*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("add_region()");
}

std::vector<RegionID> Datastructures::all_regions()
{
    // Replace the line below with your implementation
    throw NotImplemented("all_regions()");
}

Name Datastructures::get_region_name(RegionID /*id*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("get_region_name()");
}

std::vector<Coord> Datastructures::get_region_coords(RegionID /*id*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("get_region_coords()");
}

bool Datastructures::add_subregion_to_region(RegionID /*id*/, RegionID /*parentid*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("add_subregion_to_region()");
}

bool Datastructures::add_station_to_region(StationID /*id*/, RegionID /*parentid*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("add_station_to_region()");
}

std::vector<RegionID> Datastructures::station_in_regions(StationID /*id*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("station_in_regions()");
}

std::vector<RegionID> Datastructures::all_subregions_of_region(RegionID /*id*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("all_subregions_of_region()");
}

std::vector<StationID> Datastructures::stations_closest_to(Coord /*xy*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("stations_closest_to()");
}

bool Datastructures::remove_station(StationID /*id*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("remove_station()");
}

RegionID Datastructures::common_parent_of_regions(RegionID /*id1*/, RegionID /*id2*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("common_parent_of_regions()");
}

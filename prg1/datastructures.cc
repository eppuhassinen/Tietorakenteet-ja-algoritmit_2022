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

/**
 * @brief Datastructures::Datastructures
 */
Datastructures::Datastructures()
{
    // Write any initialization you need here
    station_map_ = {};
}

/**
 * @brief Datastructures::~Datastructures
 */
Datastructures::~Datastructures()
{
    // Write any cleanup you need here
}

/**
 * @brief Datastructures::station_count
 * @return
 */
unsigned int Datastructures::station_count()
{
    // Replace the line below with your implementation
    if ( station_map_.empty() ) {return 0;}

    return station_map_.size();
}

/**
 * \brief Datastructures::clear_all
 */
void Datastructures::clear_all()
{
    // Replace the line below with your implementation
    station_map_.clear();

}

/**
 * @brief Datastructures::all_stations
 * @return
 */
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

/**
 * @brief Datastructures::add_station
 * @param id
 * @param name
 * @param xy
 * @return
 */
bool Datastructures::add_station(StationID id, const Name& name, Coord xy)
{
    // Replace the line below with your implementation
    if ( station_map_.find(id) != station_map_.end() ) { return false; }

    station new_station;
    new_station.id = id;
    new_station.name = name;
    new_station.coord = xy;
    new_station.trains = {};

    station_map_[id] = (new_station);
    return true;
}

/**
 * @brief Datastructures::get_station_name
 * @param id
 * @return
 */
Name Datastructures::get_station_name(StationID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )

    if ( station_map_.find(id) == station_map_.end() ) { return NO_NAME; }

    return station_map_.at(id).name;

}

/**
 * @brief Datastructures::get_station_coordinates
 * @param id
 * @return
 */
Coord Datastructures::get_station_coordinates(StationID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    if ( station_map_.find(id) == station_map_.end() ) { return NO_COORD; }

    return station_map_.at(id).coord;

}

/**
 * @brief Datastructures::stations_alphabetically
 * @return
 */
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

/**
 * @brief Datastructures::stations_distance_increasing
 * @return
 */
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

/**
 * @brief Datastructures::find_station_with_coord
 * @param xy
 * @return
 */
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

/**
 * @brief Datastructures::change_station_coord
 * @param id
 * @param newcoord
 * @return
 */
bool Datastructures::change_station_coord(StationID id, Coord newcoord)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    if ( station_map_.find(id) == station_map_.end() ) {return false;}

    station_map_[id].coord = newcoord;
    return true;
}

/**
 * @brief Datastructures::add_departure
 * @param stationid
 * @param trainid
 * @param time
 * @return
 */
bool Datastructures::add_departure(StationID stationid, TrainID trainid, Time time)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )

    // tests if station exists
    if ( station_map_.find(stationid) == station_map_.end() ) { return false; }
    // tests if train already exists
    if ( station_map_[stationid].trains.find(trainid) != station_map_[stationid].trains.end())
    {
        return false;
    }

    station_map_[stationid].trains[trainid] = time;
    return true;
}

/**
 * @brief Datastructures::remove_departure
 * @param stationid
 * @param trainid
 * @param time
 * @return
 */
bool Datastructures::remove_departure(StationID stationid, TrainID trainid, Time time)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )

    // tests if station exists
    auto stationit = station_map_.find(stationid);
    if ( stationit == station_map_.end() ) { return false; }
    // tests if train already exists
    auto trainit = station_map_[stationid].trains.find(trainid);
    if ( trainit == station_map_[stationid].trains.end()) {return false;}
    if ( trainit->second != time ) {return false;}

    stationit->second.trains.erase(trainit);
    return true;


}

/**
 * @brief Datastructures::station_departures_after
 * @param stationid
 * @param time
 * @return
 */
std::vector<std::pair<Time, TrainID>> Datastructures::station_departures_after(StationID stationid, Time time)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )

    // tests if station exists
    auto stationit = station_map_.find(stationid);
    if ( stationit == station_map_.end() ) { return {std::make_pair(NO_TIME, NO_TRAIN)}; }

    std::vector<std::pair<Time, TrainID>> train_vector = {};
    for (auto &current_train : stationit->second.trains)
    {
        if (current_train.second < time) {continue;}

        train_vector.push_back(std::make_pair(current_train.second, current_train.first));
    }

    sort(train_vector.begin(), train_vector.end(), [&](std::pair<Time, TrainID> tr1, std::pair<Time, TrainID> tr2)
    {
        if (tr1.first != tr2.first) {return tr1.first < tr2.first;}

        return tr1.second < tr2.second;
    });

    return train_vector;
}

/**
 * @brief Datastructures::add_region
 * @param id
 * @param name
 * @param coords
 * @return
 */
bool Datastructures::add_region(RegionID id, const Name &name, std::vector<Coord> coords)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    if (region_map_.find(id) != region_map_.end()) {return false;}

    region newregion;
    newregion.id = id;
    newregion.coords = coords;
    newregion.name = name;

    region_map_[id] = newregion;
    return true;
}

/**
 * @brief Datastructures::all_regions
 * @return
 */
std::vector<RegionID> Datastructures::all_regions()
{
    // Replace the line below with your implementation
    std::vector<RegionID> regionids = {};
    for (auto &region : region_map_)
    {
        regionids.push_back(region.first);
    }
    return regionids;
}

/**
 * @brief Datastructures::get_region_name
 * @param id
 * @return
 */
Name Datastructures::get_region_name(RegionID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    auto it = region_map_.find(id);
    if (it == region_map_.end()) {return NO_NAME;}

    return it->second.name;
}

/**
 * @brief Datastructures::get_region_coords
 * @param id
 * @return
 */
std::vector<Coord> Datastructures::get_region_coords(RegionID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    auto it = region_map_.find(id);
    if (it == region_map_.end()) {return {NO_COORD};}

    return it->second.coords;
}

/**
 * @brief Datastructures::add_subregion_to_region
 * @param id
 * @param parentid
 * @return
 */
bool Datastructures::add_subregion_to_region(RegionID id, RegionID parentid)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    auto it = region_map_.find(id);
    auto parentit = region_map_.find(parentid);
    auto end = region_map_.end();
    if (it == end or parentit == end) {return false;}

    if (it->second.parent != nullptr) {return false;}

    parentit->second.subregions.insert(&it->second);
    it->second.parent = &parentit->second;
    return true;

}

/**
 * @brief Datastructures::add_station_to_region
 * @param id
 * @param parentid
 * @return
 */
bool Datastructures::add_station_to_region(StationID id, RegionID parentid)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    auto it = station_map_.find(id);
    auto parentit = region_map_.find(parentid);

    if (it == station_map_.end() or parentit == region_map_.end()) {return false;}

    if (it->second.parent != NO_REGION) {return false;}

    it->second.parent = parentid;
    parentit->second.stations.insert(&it->second);

    return true;
}

/**
 * @brief Datastructures::station_in_regions
 * @param id
 * @return
 */
std::vector<RegionID> Datastructures::station_in_regions(StationID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    auto it = station_map_.find(id);
    if (it == station_map_.end()) {return {NO_REGION};}
    std::vector<RegionID> region_vector = {};

    if (station_map_[id].parent == NO_REGION) {return {};}

    auto currentit = region_map_.find(it->second.parent);

    if (currentit->second.id == NO_REGION) {return region_vector;}
    region_vector.push_back(currentit->second.id);

    region* current = nullptr;
    current = currentit->second.parent;

    while (current != nullptr)
    {
        region_vector.push_back(current->id);
        current = current->parent;
    }

    return region_vector;
}

/**
 * @brief Datastructures::all_subregions_of_region
 * @param id
 * @return
 */
std::vector<RegionID> Datastructures::all_subregions_of_region(RegionID id)
{
    // Replace the line below with your implementation
    if (region_map_.find(id) == region_map_.end()) {return {NO_REGION};}
    std::vector<RegionID> regions = {};

    for (auto sub : region_map_[id].subregions)
    {
        rec_subregions_of_region(regions, sub);
    }
    return regions;

}

/**
 * @brief Datastructures::stations_closest_to
 * @param xy
 * @return
 */
std::vector<StationID> Datastructures::stations_closest_to(Coord xy)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    std::vector<std::pair<StationID, Coord>> station_vec;
    for (auto &station : station_map_)
    {
        Coord coord = {station.second.coord.x - xy.x, station.second.coord.y - xy.y};
        auto pair = std::make_pair(station.first, coord);
        station_vec.push_back(pair);
    }

    sort(station_vec.begin(), station_vec.end(), [&](auto p1, auto p2){
        return p1.second < p2.second;
    });

    std::vector<StationID> organized = {};

    unsigned long int i = 0;

    while (i < 3 and i < station_vec.size())
    {
        organized.push_back(station_vec[i].first);
        ++i;
    }
    return organized;
}

/**
 * @brief Datastructures::remove_station
 * @param id
 * @return
 */
bool Datastructures::remove_station(StationID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    auto it = station_map_.find(id);
    if (it == station_map_.end()) {return false;}

    auto parentit = region_map_.find(it->second.parent);

    if (parentit != region_map_.end())
    {
        parentit->second.stations.erase(&station_map_[id]);
    }

    station_map_.erase(id);
    return true;

}

/**
 * @brief Datastructures::common_parent_of_regions
 * @param id1
 * @param id2
 * @return
 */
RegionID Datastructures::common_parent_of_regions(RegionID id1, RegionID id2)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    if (region_map_.find(id1) == region_map_.end() or
            region_map_.find(id2) == region_map_.end()) {return NO_REGION;}

    std::vector<RegionID> id1_parents = {region_map_[id1].id};
    auto current_parent = region_map_[id1].parent;
    while (current_parent != nullptr)
    {
        id1_parents.push_back(current_parent->id);
        current_parent = current_parent->parent;
    }

    if (std::find(id1_parents.begin(), id1_parents.end(), id2) != id1_parents.end()) {return id2;}

    current_parent = region_map_[id2].parent;
    while (current_parent != nullptr)
    {
        if (std::find(id1_parents.begin(), id1_parents.end(), current_parent->id) != id1_parents.end()) {return current_parent->id;}
        current_parent = current_parent->parent;
    }

    return NO_REGION;


}
/**
 * @brief Datastructures::rec_subregions_of_region
 * @param subregions
 * @param current_region
 */
void Datastructures::rec_subregions_of_region(std::vector<RegionID> &subregions, region *current_region)
{
    if (current_region == nullptr) {return;}

    subregions.push_back(current_region->id);

    for (auto sub : current_region->subregions)
    {
        rec_subregions_of_region(subregions, sub);
    }
}

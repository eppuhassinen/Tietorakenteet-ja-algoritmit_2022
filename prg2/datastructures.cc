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
 * @brief Datastructures::Datastructures Istuskelen aamukahveella
 * Ei kuppi meinaa pysyä kourassa
 */
Datastructures::Datastructures()
{
    // Write any initialization you need here
    station_map_ = {};
}

/**
 * @brief Datastructures::~Datastructures
 * Päässä jyskii kanuunat
 * Kuin joskus itärintamalla
 */
Datastructures::~Datastructures()
{
    // Write any cleanup you need here
}

/**
 * @brief Datastructures::station_count Joku hyyskässä nyyhkii
 * Se on Aimo
 * @return Se peremmälle pirttiin vetelehtii
 */
unsigned int Datastructures::station_count()
{
    // Replace the line below with your implementation
    if ( station_map_.empty() ) {return 0;}

    return station_map_.size();
}

/**
 * \brief Datastructures::clear_all Ja haisee kuin rankkitynnyri
 * Samalta haiskahdan minäkin
 */
void Datastructures::clear_all()
{
    // Replace the line below with your implementation
    station_map_.clear();

}

/**
 * @brief Datastructures::all_stations Yhdessähän pohjia kiskottiin
 * Taksin maksoi Aimo
 * @return Hirsipuu kutsuu
 * Pirkka-kraka hamppuköytehen vaihtuu
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
 * @brief Datastructures::add_station Jo loppuu vihdoinkin tämä kidutus
 * @param id Humppakauhut unohtuu
 * @param name Risun lailla niskanikamani taittuu
 * @param xy Joo, pihalle pystyyn vaan kunnon hirsipuu
 * @return Lai LaiLaiLaiLaiLai Lai LaiLaiLai Lai
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
 * @brief Datastructures::get_station_name Mielikuvat eilisestä hatarat
 * Humppakukot hurmasivat humppakanat
 * @param id Vaan kanalaan päässyt ei kumpikaan
 * @return Keskenään kukot jäivät kiekumaan
 */
Name Datastructures::get_station_name(StationID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )

    if ( station_map_.find(id) == station_map_.end() ) { return NO_NAME; }

    return station_map_.at(id).name;

}

/**
 * @brief Datastructures::get_station_coordinates Siipi maassa on Aimo
 * Järki seisoo
 * @param id Ja muu ei seisokkaan
 * Järki Seisoo
 * @return Palava siili ruokatorvessa
 */
Coord Datastructures::get_station_coordinates(StationID id)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    if ( station_map_.find(id) == station_map_.end() ) { return NO_COORD; }

    return station_map_.at(id).coord;

}

/**
 * @brief Datastructures::stations_alphabetically Aamukahviin heräystä lorautan
 * Aimo vähän epäröi vaan tekee saman
 * @return Ja kohta tilaa taksin Aimo
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
 * @brief Datastructures::stations_distance_increasing Hirsipuu kutsuu
 * Pirkka-kraka hamppuköytehen vaihtuu
 * @return Jo loppuu vihdoinkin tämä kidutus
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
 * @brief Datastructures::find_station_with_coord Humppa kauhut unohtuu
 * Risun lailla niskanikamani taittuu
 * @param xy Joo, pihalle pystyyn vaan kunnon hirsipuu
 * @return Hirsipuu kutsuu
 * Pirkka-kraka hamppuköytehen vaihtuu
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
 * @brief Datastructures::change_station_coord Jo loppuu vihdoinkin tämä kidutus
 * Humppa kauhut unohtuu
 * @param id Risun lailla niskanikamani taittuu
 * @param newcoord Joo, pihalle pystyyn vaan
 * Joo, pihalle pystyyn vaan
 * @return Joo, pihalle pystyyn vaan laittakaa se hirsipuu
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
 * @brief Datastructures::add_departure Kaverit nauraa kun mullei oo heilaa
 * @param stationid Heittelen tikkaa ja kaatelen keilaa
 * @param trainid Sopivaa etsin vaan kaikki mut teilaa
 * @param time Ruma ja yksin kuin lotja ma seilaan
 * @return Perjantai-iltaisin ma tekarit harjaan
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
 * @brief Datastructures::remove_departure Jakauksen liisteröin syljellä otsaan
 * @param stationid Jospa ma tanaan sen oikean löydän
 * @param trainid Tai kenet tahansa, edes sen väärän
 * @param time Kanssansa humppaisin, nousuun auringon
 * @return Aamulla mentäisiin, baariin Elannon
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
 * @brief Datastructures::station_departures_after Että mua riipoo kun toiset vaan tanssaa
 * @param stationid Kuin hevosta Henry, ne paria vaihtaa
 * @param time Jospa ma tänään, sen oikean nappaan
 * @return En periksi anna, tuumin ja pokkaan
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
 * @brief Datastructures::add_region Joku elää humpalla, ma elan sen alla
 * @param id Se talvella hyytää jo menomatkalla
 * @param name Se minua kutsuu, ja minähän vastaan
 * @param coords Ruma ja yksin, ja heilaa vailla
 * @return Kanssansa humppaisin, nousuun auringon
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
 * @brief Datastructures::all_regions Aamulla mentäisiin, baariin Elannon
 * @return Kahvit juotaisiin, kera pullan eilisen
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
 * @brief Datastructures::get_region_name Puolella hinnalla, saa kun tinkaisee
 * @param id Kanssansa humppaisin, nousuun auringon
 * @return Aamulla mentäisiin, baariin Elannon
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
 * @brief Datastructures::get_region_coords Kahvit juotaisiin, kera pullan eilisen
 * @param id Puolella hinnalla, saa kun tinkaisee
 * @return Söin liivistä hihat kun hautasi näin
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
 * @brief Datastructures::add_subregion_to_region Mä nostatin vihat ja tansseihin jäin
 * @param id Oon tanssaava kersantti vain
 * @param parentid Kai humpata saan, humpata saan
 * @return Ei kylmyytes estää voi humppaustain
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
 * @brief Datastructures::add_station_to_region Hautaan asti humppaan
 * @param id Söin kengistä pohjat kun arkkusi näin
 * @param parentid Mä tempasin pohjat ja tansseihin jäin
 * @return On humppaava suntio vain
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
 * @brief Datastructures::station_in_regions On humppaava suntio vain
 * @param id Mun seuranain, seuranain
 * @return Kai suntio kestää voi humppaustain
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
 * @brief Datastructures::all_subregions_of_region Hautaan asti humppaan
 * @param id Päälaulanta petteri terävä
 * @return Niin kauan kun ma muistan on ollut humppaa
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
 * @brief Datastructures::stations_closest_to sen villit rytmit raikui jo nuijasodassa
 * @param xy sitä oli paljon ja se oli mahtavaa
 * @return mä vain tuumaan yksin tuumaan
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
 * @brief Datastructures::remove_station kuka humpan seisauttaa? Nyt pitkätukat veivaa
 * @param id Nyt pitkätukat veivaa jotain kevytmetallia
 * @return ja diskoissa ne soittaa pelkkää puheohjelmaa
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
 * @brief Datastructures::common_parent_of_regions ja tukattomat tivaa meiltä sotamuistoja
 * @param id1 meiltä sotamuistoja mä vain tuumaan
 * @param id2 yksin tuumaan kuka humpan seisauttaa?
 * @return Alakerran vihtahousu raapii partaansa
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
 * @brief Datastructures::rec_subregions_of_region Alakerran vihtahousu raapii partaansa
 * @param subregions yläkerran maitoparta meinaa tehdä housuunsa
 * @param current_region kun HUMPPA TULEE LUJAA JA PÄÄHÄN KUMAUTTAA
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

Distance Datastructures::distance_between(StationID station1, StationID station2)
{
    Coord c1 = station_map_[station1].coord;
    Coord c2 = station_map_[station2].coord;
    Distance distance = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));

    return distance;

}

// prg2

bool Datastructures::add_train(TrainID trainid, std::vector<std::pair<StationID, Time> > stationtimes)
{


    if (train_map_.find(trainid) != train_map_.end())   { return false; }

    for (auto &n : stationtimes)
    {
        if (station_map_.find(n.first) == station_map_.end()) { return false; }
    }

    for (auto &n : stationtimes)
    {
        add_departure(n.first, trainid, n.second);
    }

    train new_train;
    new_train.id = trainid;
    new_train.stationtimes = stationtimes;

    train_map_[trainid] = new_train;
    return true;
}

std::vector<StationID> Datastructures::next_stations_from(StationID id)
{
    if (station_map_.find(id) == station_map_.end()) {return {NO_STATION};}

    std::vector<StationID> next_stations = {};

    for (auto &n : station_map_[id].trains)
    {
        auto ptr = train_map_[n.first].stationtimes.begin();
        auto end = train_map_[n.first].stationtimes.end();
        while (ptr < end)
        {
            if(ptr->first == id)
            {
                if ((ptr + 1)!= end)
                {
                    next_stations.push_back((ptr + 1)->first);
                    ptr = end - 1;
                }
            }
            ptr++;
        }
    }
    return next_stations;
}

std::vector<StationID> Datastructures::train_stations_from(StationID stationid, TrainID trainid)
{
    if (station_map_.find(stationid) == station_map_.end()) {return {NO_STATION};}
    if (station_map_[stationid].trains.find(trainid) == station_map_[stationid].trains.end()) {return {NO_STATION};}
    if (train_map_.find(trainid) == train_map_.end()) {return {NO_STATION};}


    std::vector<StationID> next_stations = {};

    auto ptr = train_map_[trainid].stationtimes.begin();
    auto end = train_map_[trainid].stationtimes.end();

    while (ptr < end)
    {
        if (ptr->first == stationid) { ptr++; break; }
        ptr++;
    }

    while (ptr < end)
    {
        next_stations.push_back(ptr->first);
        ptr++;
    }

    return next_stations;

}

void Datastructures::clear_trains()
{
    for (auto &p : train_map_)
    {
        for (auto &n : p.second.stationtimes)
        {
            remove_departure(n.first, p.first, n.second);
        }
    }

    train_map_.clear();
}

std::vector<std::pair<StationID, Distance>> Datastructures::route_any(StationID fromid, StationID toid)
{
    if (station_map_.find(fromid) == station_map_.end() || station_map_.find(toid) == station_map_.end())
    {
        return {std::make_pair(NO_STATION,NO_DISTANCE)};
    }



    std::set<StationID> checked_stations;
    std::map<StationID,current_station> checked_stations_info;

    std::queue<std::pair<StationID, current_station>> que;

    current_station start;
    start.id = fromid;
    start.distance_from_start = 0;
    start.from = NO_STATION;
    que.push(std::make_pair(fromid,start));

    current_station current;
    while (true)
    {
        if (que.empty()) {return {};}

        current = que.front().second;
        checked_stations_info.insert(que.front());




        for (StationID &next : next_stations_from(current.id))
        {
            if (checked_stations.find(next) == checked_stations.end())
            {
                current_station next_station;
                next_station.id = next;
                next_station.from = current.id;
                next_station.distance_from_start = current.distance_from_start + distance_between(current.id, next);

                que.push(std::make_pair(next, next_station));


                checked_stations.insert(next);
            }
        }
        if (current.id == toid) {break;}
        que.pop();

    }


    std::vector<std::pair<StationID, Distance>> route;
    auto temp = current;
    while (temp.from != NO_STATION)
    {
        route.push_back(std::make_pair(temp.id, temp.distance_from_start));
        temp = checked_stations_info[temp.from];
    }

    route.push_back(std::make_pair(temp.id, temp.distance_from_start));

    std::reverse(route.begin(),route.end());

    return route;



}

std::vector<std::pair<StationID, Distance>> Datastructures::route_least_stations(StationID /*fromid*/, StationID /*toid*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("route_least_stations()");
}

std::vector<StationID> Datastructures::route_with_cycle(StationID /*fromid*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("route_with_cycle()");
}

std::vector<std::pair<StationID, Distance>> Datastructures::route_shortest_distance(StationID /*fromid*/, StationID /*toid*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("route_shortest_distance()");
}

std::vector<std::pair<StationID, Time>> Datastructures::route_earliest_arrival(StationID /*fromid*/, StationID /*toid*/, Time /*starttime*/)
{
    // Replace the line below with your implementation
    // Also uncomment parameters ( /* param */ -> param )
    throw NotImplemented("route_earliest_arrival()");
}

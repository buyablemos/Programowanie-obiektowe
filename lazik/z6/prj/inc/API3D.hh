#ifndef API3D_HH
#define API3D_HH

#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

class API3D{

std::shared_ptr<drawNS::Draw3DAPI> api;

public:

API3D(){std::shared_ptr<drawNS::Draw3DAPI>tmp(new drawNS::APIGnuPlot3D(-20,20,-20,20,-0.1,5,0)); this->api=tmp;};

std::shared_ptr<drawNS::Draw3DAPI> getpointer(){return api;}

};

#endif
#pragma once

template<class PositionType>
class Order
{
	protected:

		PositionType source;
		PositionType destination;

		double volume;
		double weight;
		double value;

		int deliveryTimeOre; 
		bool fragile;
		bool perishable;

	public:


		Order(PositionType source_ = PositionType(),
			PositionType destination_ = PositionType(),
			double volume_ = 0.0,
			double weight_ = 0.0,
			double value_ = 0.0,
			int deliveryTimeOre_ = 0,
			bool fragile_ = false,
			bool perishable_ = false);


		double costLivrare();
};

template<class PositionType>
Order<PositionType>::Order(PositionType source_ = PositionType(), 
				 PositionType destination_ = PositionType(), 
				 double volume_ = 0.0, 
				 double weight_ = 0.0, 
				 double value_ = 0.0, 
				 int deliveryTimeOre_ = 0, 
				 bool fragile_ = false, 
				 bool perishable_ = false) {
	
	source = source_;
	destination = destination_;
	volume = volume_;
    weight = weight_;
	value = value_;
	deliveryTimeOre = deliveryTimeOre_;
	fragile = fragile_;
	perishable = perishable_;
}

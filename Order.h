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

		int deliveryTimelimit;
		int sendingTime;
		bool fragile;
		bool perishable;

	public:


		Order(PositionType source_ = PositionType(),
			PositionType destination_ = PositionType(),
			double volume_ = 0.0,
			double weight_ = 0.0,
			double value_ = 0.0,
			int deliveryTimelimit_ = 0,
			int sendingTime_ = 0,
			bool fragile_ = false,
			bool perishable_ = false);


		double costLivrare();

		PositionType getSource() const;
};

template<class PositionType>
Order<PositionType>::Order(PositionType source_ = PositionType(), 
				 PositionType destination_ = PositionType(), 
				 double volume_ = 0.0, 
				 double weight_ = 0.0, 
				 double value_ = 0.0, 
				 int deliveryTimelimit_ = 0,
				 int sendingTime_ = 0,
				 bool fragile_ = false, 
				 bool perishable_ = false) {
	
	source = source_;
	destination = destination_;
	volume = volume_;
    weight = weight_;
	value = value_;
	deliveryTimelimit = deliveryTimelimit_;
	sendingTime = sendingTime_;
	fragile = fragile_;
	perishable = perishable_;
}


template<class PositionType>
PositionType Order<PositionType>::getSource() const {
	return source;
}
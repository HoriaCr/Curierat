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


		double deliveryCost();

		PositionType getSource() const;

		PositionType getDestination() const;

		double computePrice() const;

		int getTimelimit() const;
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

template<class PositionType>
PositionType Order<PositionType>::getDestination() const {
	return destination;
}

template<class PositionType>
double Order<PositionType>::computePrice() const {
	return value / 25.0 + 100.0 / deliveryTimelimit + 2.0 * perishable + 2.0 * fragile + volume / 1000.0 + weight / 100.0;
}

template<class PositionType>
int Order<PositionType>::getTimelimit() const {
	return sendingTime + deliveryTimelimit;
}
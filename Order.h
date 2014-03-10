#pragma once

template<class PositionType>
class Order
{
	protected:

		PositionType source;
		PositionType destination;
        
        double value;
		float volume;
		float weight;
		

		int deliveryTimelimit;
		int sendingTime;
		bool fragile;
		bool perishable;

	public:

		Order(
            PositionType source_,
			PositionType destination_,
			float volume_,
			float weight_,
			double value_,
			int deliveryTimelimit_,
			int sendingTime_,
			bool fragile_,
			bool perishable_);


		PositionType getSource() const;

		PositionType getDestination() const;

		double computePrice() const;

		float getWeight() const;

		float getVolume() const;

		int getTimelimit() const;
};

template<class PositionType>
Order<PositionType>::Order(PositionType source_ = PositionType(), 
				 PositionType destination_ = PositionType(), 
				 float volume_ = 0.0, 
				 float weight_ = 0.0, 
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

template<class PositionType>
float Order<PositionType>::getWeight() const {
	return weight;
}

template<class PositionType>
float Order<PositionType>::getVolume() const {
	return volume;
}


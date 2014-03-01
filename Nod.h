
template<class DataType>
class Nod
{
	protected:
		Nod *previous;
		Nod *next;
		DataType data;
	
	public:
		Nod() {
			previous = NULL;
			next = NULL;
			data = DataType();
		}

};
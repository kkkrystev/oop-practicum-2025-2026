#include <iostream>
#include <fstream>
#include <cstring>

namespace constants {
	const int MAX_NAME_LEN = 32;
	const char DEFAULT_DEVICE_NAME[] = "Placeholder";
	const double DEFAULT_POWER = 0.0;
	const double DEFAULT_MAX_POWER = 100.0;
	const double DEFAULT_PRICE = 0.0;
}

enum class Brand {
	Samsung,
	Philips,
	Sony,
	Bosch,
	Unknown
};

namespace BrandUtils {
	const char* toString(Brand b) {
		switch (b) {
		case Brand::Samsung: return "Samsung";
		case Brand::Philips: return "Philips";
		case Brand::Sony:    return "Sony";
		case Brand::Bosch:   return "Bosch";
		default:             return "Unknown";
		}
	}

	Brand fromInt(int x) {
		switch (x) {
		case 0: return Brand::Samsung;
		case 1: return Brand::Philips;
		case 2: return Brand::Sony;
		case 3: return Brand::Bosch;
		default: return Brand::Unknown;
		}
	}
}

class Device {
	char name[constants::MAX_NAME_LEN + 1];
	Brand brand;
	double price;

	double power;
	double maxPower;

	bool isOn;
	bool isBroken;

	void enforcePowerLimits() {
		if (power > maxPower) {
			power = maxPower;
			isBroken = true;
			isOn = false;
		}
	}

	void safeCopyName(const char* src) {
		if (!src) {
			name[0] = '\0';
			return;
		}
		std::strncpy(name, src, constants::MAX_NAME_LEN);
		name[constants::MAX_NAME_LEN] = '\0';
	}

public:
	Device()
		: brand(Brand::Unknown), 
		power(constants::DEFAULT_POWER), 
		maxPower(constants::DEFAULT_MAX_POWER),
		price(constants::DEFAULT_PRICE), isOn(false), 
		isBroken(false) 
	{
		safeCopyName(constants::DEFAULT_DEVICE_NAME);
	}

	Device(const char* n, Brand b, double maxP, double pr)
		: brand(b), 
		power(0.0), 
		maxPower(maxP), 
		price(pr),
		isOn(false), 
		isBroken(false) 
	{
		safeCopyName(n);
	}

	const char* getName() const { return name; }
	Brand getBrand() const { return brand; }
	double getPower() const { return power; }
	double getMaxPower() const { return maxPower; }
	double getPrice() const { return price; }
	bool getIsOn() const { return isOn; }
	bool getIsBroken() const { return isBroken; }

	void increasePower(double watts) {
		if (isBroken || watts <= 0) return;

		power += watts;
		enforcePowerLimits();
	}

	void decreasePower(double watts) {
		if (watts <= 0) 
			return;

		power -= watts;
		if (power < 0) 
			power = 0;
	}

	void togglePower() {
		if (isBroken) 
			return;
		isOn = !isOn;
	}

	void repair() {
		if (!isBroken) return;

		isBroken = false;
		power = 0;
		isOn = false;
	}

	void applyDiscount(double percent) {
		if (percent <= 0 || percent > 100) return;

		price -= price * (percent / 100.0);
		if (price < 0) price = 0;
	}

	void setName(const char* newName) {
		safeCopyName(newName);
	}

	void setMaxPower(double maxP) {
		if (maxP <= 0) return;

		maxPower = maxP;
		enforcePowerLimits();
	}

	void setPrice(double p) {
		if (p >= 0) 
			price = p;
	}

	void save(std::ostream& os) const {
		os << name << " "
			<< (int)brand << " "
			<< power << " "
			<< maxPower << " "
			<< price << " "
			<< isOn << " "
			<< isBroken << "\n";
	}

	void load(std::istream& is) {
		int brandInt = 0;

		is >> name
			>> brandInt
			>> price
			>> power
			>> maxPower
			>> isOn
			>> isBroken;

		brand = static_cast<Brand>(brandInt);

		if (maxPower <= 0) maxPower = constants::DEFAULT_MAX_POWER;

		enforcePowerLimits();
	}
};

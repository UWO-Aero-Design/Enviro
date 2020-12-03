//From aero-cpp-lib/include/Sensors.hpp

/**
 * @brief Raw environmental sensor data 
 */
struct __attribute__((__packed__)) Enviro_t
{
    uint16_t altitude;
    uint16_t temperature; 
    uint16_t pressure; 
};

/**
 * @brief Abstract environmental sensor definition
 */
class EnviroSensor
{
public:
    /** @brief Defines configuration data for the environmental sensor */
    struct Config_t
    {
        // Can add things like offsets here
        // Make sure to include defaults here
    };

    /**
     * @brief Initializes the environmental sensor
     * 
     * @return true if initialization was successful
     * @return false if initialization was unsuccessful
     */
    virtual bool init( ) = 0;

    /**
     * @brief Initializes the environmental sensor with user configuration
     * 
     * @param config user selected environmental sensor configuration
     * @return true if initialization was successful
     * @return false if initialization was unsuccessful
     */
    bool init( EnviroSensor::Config_t config )
    {
        m_config = config;
        init();
    }

    /**
     * @brief Update the environmental sensor data
     * 
     * @return true if update was successful
     * @return false if update was unsuccessful
     */
    virtual bool update( ) = 0;

    /**
     * @brief Get environmental sensor data
     * 
     * @return const def::Enviro_t& reference to environmental sensor's data struct
     */
    const def::Enviro_t& data(void) { return m_data; }

    /**
     * @brief Destructor
     */
    virtual ~EnviroSensor(){}

protected:
    // Hidden constructor that only children can redefine
    EnviroSensor(){}

    // Member variables
    def::Enviro_t m_data;      // For environmental sensor data
    EnviroSensor::Config_t m_config; // For environmental sensor configuration
};

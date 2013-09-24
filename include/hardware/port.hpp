#ifndef PORT_HPP
#define PORT_HPP

//! \brief I/O Port of the microcontroller
//! \param ID : index of the port
template<int ID>
class Port {
public:
  //! \brief IO configuration of a pin
  enum PinConfig {
    INPUT,    //!< input mode, the pin cannot be written
    OUTPUT,   //!< output mode, the pin can be read/written
    DISABLED  //!< disabled mode, the pin cannot be used at all
  };

  //! \brief Configure the Port as I/O
  static inline void init(void);
  //! \brief Makes the port available for another purpose
  static inline void quit(void);

  //! \brief Set each pin status (i/o)
  //! \param io : integer representing each pin config
  /*!
    The size of the integer is hardware-dependent.
    The N-th bit of the integer is the config of the N-th pin of the port.
    - 0 for setting the pin as input
    - 1 for setting the pin as output
    \warning Will throw a run-time error if the pin is set as output and is not available as i/o pin.
   */
  template<typename T> static inline void setIo(T);

  //! \brief get the port's pins values
  template<typename T> static inline T getValue(void);

  //! \brief set the port's pins values
  //! \param val : integer representing each pin state
  /*!
    The size of the integer is hardware-dependent.
    The N-th bit of the integer will be the state of the N-th pin of the port.
    If the pin is in input or disabled mode, its value must be 0 (will throw a run-time error in the other case).
   */
  template<typename T> static inline void setValue(const T&);

  //! \brief The io pin of the microcontroller
  //! \param PID : pin index
  /*!
    The number of pin available is generally 8, but can be hardware-dependent.
   */
  template<int PID>
  class Pin {
  public:
    //! \brief Set pin configuration
    template<enum PinConfig CONF> static inline void setIo(void);
    //! \brief Get pin value in the required format
    template<typename T> static inline T getValue(void);
    //! \brief Set pin value (converted from the required format)
    template<typename T> static inline void setValue(const T&);
  };
};

#endif//PORT_HPP

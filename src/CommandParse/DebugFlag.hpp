#ifndef NOPC_DEBUGFLAG_HPP
#define NOPC_DEBUGFLAG_HPP

extern bool DebugFlag;
extern bool VerboseFlag;

#define IFDEBUG(X) if (DebugFlag) { X; }
#define IFVERBOSE(X) if (VerboseFlag) {X; }

// TODO: Create a logger for both Debug and Verbose

#define LOG_DEBUG(msg) IFDEBUG( \
    std::cerr << "\033[31;1;1m  DEBUG\033[0m " << __FILE__ << ":" << __LINE__ << "\t" << msg << std::endl; \
)

#define LOG_VERBOSE(msg) IFVERBOSE( \
    std::cerr << "\033[33;1;1mVERBOSE\033[0m " << __FILE__ << ":" << __LINE__ << "\t" << msg << std::endl; \
)

#define LOG_ERROR(msg) \
    std::cerr << "\033[31;1;1m  ERROR " << __FILE__ << ":" << __LINE__ << "\t" << msg << "\033[0m" << std::endl; \

#endif //NOPC_DEBUGFLAG_HPP

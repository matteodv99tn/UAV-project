file(GLOB rospo_srcs CONFIGURE_DEPENDS "*.cpp")
target_sources(rospo PRIVATE ${rospo_srcs})

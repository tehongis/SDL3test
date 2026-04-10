-- SDL3 Example 1: Window and Renderer
function example_basic_window()
    local window = S3_create_window(800, 600, 0)
    print("Created window")
    
    local renderer = S3_create_renderer(window, nil)
    print("Created renderer")
    
    S3_clear(nil, renderer, 0, 0, 0, 255)
    print("Cleared screen")
end

-- SDL3 Example 2: Events
function example_events()
    local window = S3_create_window(800, 600, 0)
    
    while not S3_wait_event(window) do
        S3_pump_events(nil)
        break
    end
end

-- Box2D Example: Physics World
function example_box2d()
    -- Initialize Box2D world
    -- Create bodies
    -- Apply to renderer
end

pub struct ThreadPool {
    workers: Vec<Worker>,
}

struct Worker {
    id: usize,
    thread: Option<std::thread::JoinHandle<()>>,
}
impl ThreadPool {
    pub fn new(_size: usize) -> ThreadPool {
        assert!(_size > 0);

        let mut workers = Vec::with_capacity(_size);
        for id in 0.._size {
            workers.push(Worker { id, thread: None });
        }

        ThreadPool { workers }
    }
}

impl ThreadPool {
    pub fn execute<F>(&self, _f: F)
    where
        F: FnOnce() + Send + 'static,
    {
        // Execute the function in a thread
        std::thread::spawn(_f);
    }
}

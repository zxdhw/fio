#ifndef HITCHHIKE_H
#define HITCHHIKE_H

#include <libaio.h>
#include <stdint.h>

#define __NR_io_submit_hit 452
#define __NR_print_hit_stats 453

struct hit_stats {
	//ktime
	long ktime_time;
	long ktime_count;

	// aio stat
	long io_time_kernel;
	long io_count_kernel;

	long aio_time;
	long aio_count;

	long aio_hit_time;
	long aio_hit_count;

	long get_user_time;
	long get_user_count;

	long copy_user_time;
	long copy_user_count;

	long aio_req_time;
	long aio_req_count;

	long aio_fget_time;
	long aio_fget_count;

	long aio_prep_time;
	long aio_prep_count;

	long aio_setup_time;
	long aio_setup_count;

	long verify_time;
	long verify_count;

	long read_iter_time;
	long read_iter_count;

	// fs stat
	long file_read_iter_time;
	long file_read_iter_count;

	long fs_time;
	long fs_count;

	long dio_time;
	long dio_count;

	long filemap_wait_time;
	long filemap_wait_count;

	long iomap_time;
	long iomap_count;

	long iomap_hit_time;
	long iomap_hit_count;

	long get_page_time;
	long get_page_count;

	long bio_time;
	long bio_count;

	long hit_buf_time;
	long hit_buf_count;

	long plug_time;
	long plug_count;

	// block stat
	long fs_submit_time;
	long fs_submit_count;

	long block_time;
	long block_count;

	long submit_bio_time;
	long submit_bio_count;

	long hit_tag_time;
	long hit_tag_count;

	long req_time;
	long req_count;

	//driver
	long driver_time;
	long driver_count;

	long queue_rq_time;
	long queue_rq_count;

	long dma_time;
	long dma_count;

	long hit_cmd_time;
	long hit_cmd_count;

	long sq_time;
	long sq_count;

	long cmd_time;
	long cmd_count;

	long dma_unmap_time;
	long dma_unmap_count;

	long interrupt_time;
	long interrupt_count;

};

struct hitchhiker {
	uint32_t max;
	uint32_t in_use;
	uint32_t size;
	uint32_t res;
	uint64_t addr[126];
};

static int io_submit_hit(io_context_t ctx, long nr, struct iocb **iocbpp, 
                                    struct hitchhiker **hit_bufs) {
    return syscall(__NR_io_submit_hit, ctx, nr, iocbpp, hit_bufs);
}
static int io_stat(struct hit_stats* stats_bufs) {
    return syscall(__NR_print_hit_stats, stats_bufs);
}

#endif